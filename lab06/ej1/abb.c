#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}


abb create_leaf(abb_elem e) {
 abb leaf = malloc(sizeof(struct _s_abb));
 leaf -> elem = e;
 leaf -> left = NULL;
 leaf -> right = NULL; 
 
 return leaf;
}

static bool invrep(abb tree) {
 bool b = true;
 if (tree != NULL) {
   if (tree->left != NULL) {
   b = elem_less(tree->left->elem,tree->elem) && invrep(tree->left);
  } 
   if (tree->right != NULL && b) {
   b = b && elem_less(tree->elem,tree->right->elem) && invrep(tree->right);
  }
 }
    return b;
}

abb abb_empty(void) {
    abb tree;
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree == NULL) {
     tree =  create_leaf(e);
    } else if (elem_less(e,tree->elem)) {
       tree -> left = abb_add(tree->left,e);
      } else {
       tree -> right = abb_add(tree->right,e);
      } 
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}


bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree!=NULL) {
     if (elem_eq(tree->elem,e)) {
      exists = true;
     } else if (tree->elem < e) {
      exists = abb_exists(tree->right, e);
     } else {
      exists = abb_exists(tree->left, e);
     }
    }
    return exists;
}


unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree == NULL) {
     length = 0;
    } else {
     length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb add_sub_tree(abb right_, abb left) {
 abb right = right_;
 while (right!=NULL) {
  right = right->left;
 } 
 
 right = left;
 
 return right_;
}


/*abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb aux = tree;
    abb b = NULL;
    b = tree;
    aux = tree->left;
    tree = tree->right;
    
   while (tree!=NULL) {
     tree = tree->left;
 } 
 
 tree = aux;
 
    free(b);
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}
*/


abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (!abb_is_empty(tree)) {
        if (tree->elem==e) {
            if (tree->left==NULL && tree->right==NULL) { // caso trivial
                free(tree);
                tree=NULL;
            } else if (tree->left!=NULL && tree->right==NULL) { // caso tiene un hijo
                abb a1=tree->left, a2=tree;
                tree=a1;
                free(a2);
                a2=NULL;
            } else if (tree->left==NULL && tree->right!=NULL) { // caso tiene un hijo
                abb a1=tree->right, a2=tree;
                tree=a1;
                free(a2);
                a2=NULL;
            } else { // caso con dos hijos
                abb_elem max = abb_max(tree->left);
                tree->left = abb_remove(tree->left,max);
                tree->elem = max;
            }
        }
        else if (elem_less(tree->elem,e)){
            tree->right = abb_remove(tree->right,e);
        } else {
        tree->left = abb_remove(tree->left,e);
        }
    }
    
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem; 
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->right==NULL) {
     max_e = tree->elem;
    } else {
     max_e = abb_max(tree->right);
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->left==NULL) {
     min_e = tree->elem;
    } else {
     min_e = abb_min(tree->left);
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (!abb_is_empty(tree)){
    abb_destroy(tree->left);
    abb_destroy(tree->right);
    free(tree);
    tree=NULL;
    }
    assert(tree == NULL);
    return tree;
}

