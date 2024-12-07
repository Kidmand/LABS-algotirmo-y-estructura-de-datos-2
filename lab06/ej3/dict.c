#include <stdlib.h>
#include <assert.h>
#include "dict.h"
#include "key_value.h"
#include "string.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t dict) {
   bool b = true;
 if (dict != NULL) {
   if (dict->left!= NULL) {
   b = string_less(dict->left->key,dict->key) && invrep(dict->left);
  } 
   if (dict->right != NULL && b) {
   b = string_less(dict->key,dict->right->key) && invrep(dict->right);
  }
 }
    return b;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict)==0);
    return dict;
}

static dict_t create_word(key_t word, value_t def) {
 dict_t new_word = malloc(sizeof(struct _node_t));
 new_word -> key = word;
 new_word -> value = def;
 new_word -> right = NULL; 
 new_word -> left = NULL;
 
 return new_word;
 
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    if (dict == NULL) {
     dict = create_word(word, def);
    } else if (string_less(word,dict->key)) {
       dict -> left = dict_add(dict->left,word,def);
      } else {
       dict -> right = dict_add(dict->right,word,def);
      } 
    assert(invrep(dict) && key_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def=NULL;
    def = word;
    value_t definicion = NULL;
    assert(invrep(dict) && key_eq(def,word));
    if (dict!=NULL) {
     if (key_eq(dict->key,word)) {
      definicion = dict->value;
     } else if (key_less(dict->key, def)) {
      definicion = dict_search(dict->right, word);
     } else {
      definicion = dict_search(dict->left, word);
     }
    }
    assert((def != NULL) == dict_exists(dict, word));
    
    return definicion;
    
}

bool dict_exists(dict_t dict, key_t word) {
    key_t def=NULL;
    def = word;
    bool exists=false;
     assert(invrep(dict) && key_eq(def,word));
    if (dict!=NULL) {
     if (key_eq(dict->key,def)) {
      exists = true;
     } else if (key_less(dict->key, def)) {
      exists = dict_exists(dict->right, word);
     } else {
      exists = dict_exists(dict->left, word);
     }
    } 
    assert(invrep(dict));
    return exists;
}

unsigned int dict_length(dict_t dict) {
    assert(invrep(dict));
    size_t length = 0;
    if (dict == NULL) {
     length = 0;
    } else {
     length = 1 + dict_length(dict->left) + dict_length(dict->right);
    }
    assert(invrep(dict));
    return length;
}


static key_t dict_max(dict_t dict ) {
    key_t max_key;
    assert(invrep(dict) && dict!=NULL);
    if (dict->right==NULL) {
     max_key = dict->key;
    } else {
     max_key = dict_max(dict->right);
    }
    assert(invrep(dict) && dict_exists(dict, max_key));
    return max_key;
}


dict_t dict_remove(dict_t dict, key_t word) {
    key_t def=NULL;
    def = word;
    assert(invrep(dict) && key_eq(def, word));
       if (dict!=NULL) {
        if (key_eq(dict->key,def)) {
            if (dict->left==NULL && dict->right==NULL) { // caso trivial
                free(dict);
                dict=NULL;
            } else if (dict->left!=NULL && dict->right==NULL) { // caso tiene un hijo
                dict_t left=dict->left;
                dict_t rigth=dict;
                dict = left;
                rigth -> key = key_destroy(def);
                rigth -> value = value_destroy(rigth->value);
                free(rigth);
                rigth=NULL;
            } else if (dict->left==NULL && dict->right!=NULL) { // caso tiene un hijo
                dict_t rigth=dict->right;
                dict_t left=dict;
                dict = rigth;
                left -> key = key_destroy(def);
                left -> value = value_destroy(rigth->value);
                free(left);
                left=NULL;
            } else { // caso con dos hijos
                key_t max = dict_max(dict->left);
                dict->left = dict_remove(dict->left,max);
                dict->key = max;
            }
        }
        else if (key_less(dict->key,def)){
            dict->right = dict_remove(dict->right,word);
        } else {
        dict->left = dict_remove(dict->left,word);
        }
    }
    def = key_destroy(def);
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}


dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));
    if (dict!=NULL){
    dict_destroy(dict->left);
    dict_destroy(dict->right);
    dict -> key = key_destroy(dict->key);
    dict -> value = value_destroy(dict->value);
    free(dict);
    dict=NULL;
    }
    
    assert(dict == NULL);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
   assert(invrep(dict) && file!=NULL);
    if (dict != NULL) {
        string_dump(dict->key, stdout);
        string_dump(dict->value, stdout);
        dict_dump(dict->left, stdout);
        dict_dump(dict->right, stdout);
    }
}

dict_t dict_destroy(dict_t dict) {
    assert(invrep(dict));
    dict = dict_remove_all(dict);
    assert(dict==NULL);
    return dict;
}

