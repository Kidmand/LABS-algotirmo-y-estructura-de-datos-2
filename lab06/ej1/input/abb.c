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

/*static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}*/

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

/*static bool invrep(abb tree) {
 /*bool b, a, resultado;
 b = true;
 a = true; 
 resultado = true;
 if(tree == NULL) {
     b = true;
     a = true;
 } else {
     a = a && elem_less(tree->left->elem,tree->elem) && invrep(tree->left);
     b = b && elem_less(tree->elem, tree->right->elem) && invrep(tree->right);  
   } resultado = a && b;*/
bool b = true;

 if (tree != NULL) {
  if (tree->left != NULL) {
   b = b && elem_less(tree->left->elem,tree->elem) && invrep(tree->left);
  } else {
   b = b && elem_less(tree->elem,tree->right->elem) && invrep(tree->right);
  }
 }

    return b;
}*/




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
    } else if (!abb_exists(tree, e)) {
      if (elem_less(e,tree->elem)) {
       abb_add(tree->left,e);
      } else {
       abb_add(tree->right,e);
      }
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
     if (tree -> elem == e) {
      exists = true;
     } else if (tree->elem < e) {
      abb_exists(tree->right, e);
     } else {
      abb_exists(tree->left, e);
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

abb add_sub_tree(abb right, abb left) {
 abb pointer_aux = right; 
 while (pointer_aux!=NULL) {
  pointer_aux = pointer_aux->left;
 } 
 
 pointer_aux = left;
 
 return right;
}



abb abb_concat(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb aux, left, p; 
    aux = tree;
    p = NULL;
    left = NULL; 
    if (aux->elem == e) {
     p = aux;
     left = aux -> left;
     aux = aux -> right; 
     free(p);
     aux = add_sub_tree(aux, left);
    } else if (aux->elem < e){
      abb_remove(aux->left, e);
    } else {
      abb_remove(aux->right, e);
     }
  
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb aux = tree;
    abb b = NULL;
    if (aux->elem < e) {
     b = aux;
     abb_remove(aux->left, e);
    } else if (aux->elem > e) {
     b = aux;
     abb_remove(aux->right, e);
    } else {
     b -> right = abb_concat(tree,e);
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
     abb_max(tree->right);
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
     abb_min(tree->left);
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    abb_destroy(tree->left);
    abb_destroy(tree->right);
    free(tree);
    tree=NULL;
    assert(tree == NULL);
    return tree;
}

