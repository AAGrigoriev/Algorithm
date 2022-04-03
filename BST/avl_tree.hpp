#pragma once

#include <assert.h>
#include <iostream>

namespace avl_tree {

template <typename Key>
struct node {
  node(const Key& key)
    : key(key) {
  }
  unsigned char height = 1;
  node* left = nullptr;
  node* right = nullptr;
  Key key;
  ~node() {
    std::cout << "destructor val = " << key << std::endl;
  }
};


template <typename Key>
class AVL_tree {
  using avl_node = node<Key>;
public:
  avl_node* find(const Key& key);
  avl_node* insert(const Key& key);
  avl_node* remove(const Key& key);
  ~AVL_tree();
private:
  avl_node* root_ = nullptr;

  avl_node* find_impl(avl_node* node, const Key& key);
  avl_node* insert_impl(avl_node*& node, const Key& key);
  avl_node* remove_impl(avl_node* node, const Key& key);
  avl_node* rotate_left(avl_node* node);
  avl_node* rotate_right(avl_node* node);
  avl_node* balance(avl_node* node);
  avl_node* remove_min(avl_node* node);
  avl_node* find_min(avl_node* node);

  unsigned char height(avl_node* node);
  char balanced_factor(avl_node* node);

  void set_height(avl_node* node);
  void clear_tree(avl_node* root);
};


template <typename Key>
AVL_tree<Key>::~AVL_tree() {
  clear_tree(root_);
}


template <typename Key>
void AVL_tree<Key>::clear_tree(avl_node* root) {
  if (!root) {
    return;
  }
  clear_tree(root->left);
  clear_tree(root->right);
  delete root;
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::find(const Key& key) {
  return find_impl(root_, key);
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::find_impl(avl_node* node, const Key& key) {
  if (!node || node->key == key) {
    return node;
  }

  if (key < node->key) {
    return find_impl(node->left, key);
  } else {
    return find_impl(node->right, key);
  }
}


template <typename Key>
unsigned char AVL_tree<Key>::height(avl_node* node) {
  return node ? node->height : 0;
}


template <typename Key>
char AVL_tree<Key>::balanced_factor(avl_node* node) {
  assert(node != nullptr);
  return height(node->right) - height(node->left);
}


template <typename Key>
void AVL_tree<Key>::set_height(avl_node* node) {
  assert(node);
  auto left_height = height(node->left);
  auto right_height = height(node->right);
  node->height = (left_height > right_height ? left_height : right_height) + 1;
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::balance(avl_node* node) {
  set_height(node);
  // Вес больше справа
  auto factor = balanced_factor(node);
  if (balanced_factor(node) == 2) {
    if (balanced_factor(node->right) < 0) {
      node->right = rotate_right(node->right);
    }
    return rotate_left(node);
  } else if (balanced_factor(node) == -2) {
    if (balanced_factor(node->left) > 0) {
      node->left = rotate_left(node->left);
    }
    return rotate_right(node);
  }
  return node;
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::rotate_right(avl_node* node) {
  auto temp = node->left;
  node->left = temp->right;
  temp->right = node;
  set_height(node);
  set_height(temp);
  return temp;
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::rotate_left(avl_node* node) {
  auto temp = node->right;
  node->right = temp->left;
  temp->left = node;
  set_height(node);
  set_height(temp);
  return temp;
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::insert(const Key& key) {
  return root_ = insert_impl(root_, key);
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::insert_impl(avl_node*& node, const Key& key) {
  if (!node) {
    return new avl_node{key};
  }

  if (node->key > key) {
    node->left = insert_impl(node->left, key);
  } else if (node->key < key) {
    node->right = insert_impl(node->right, key);
  }
  return balance(node);
}


template<typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::remove(const Key& key) {
  return root_ = remove_impl(root_, key);
}


template<typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::remove_impl(avl_node* node, const Key& key) {
  if (!node) {
    return nullptr;
  }
  if (key < node->key) {
    node->left = remove_impl(node->left, key);
  } else if (key > node->key) {
    node->right = remove_impl(node->right, key);
  } else {
    avl_node* left = node->left;
    avl_node* right = node->right;
    delete node;
    if (!right) {
      return left;
    }
    avl_node* min = find_min(right);
    min->right = remove_min(right);
    min->left = left;
    return balance(min);
  }
  return balance(node);
}


template<typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::find_min(avl_node* node) {
  return node->left ? find_min(node->left) : node;
}


template <typename Key>
typename AVL_tree<Key>::avl_node* AVL_tree<Key>::remove_min(avl_node* node) {
  if (!node->left) {
    return node->right;
  }
  node->left = remove_min(node);
  return balance(node);
}

}
