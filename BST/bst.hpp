#pragma once

#include <iostream>
#include <memory>


namespace bst_tree {

template<typename Key>
struct node {
  Key val;
  node* left = nullptr;
  node* right = nullptr;
};


template <typename Key>
class BST final {
using bst_node = node<Key>;
public:
  bst_node* insert(const Key& val);
  bst_node* remove(const Key& val);
  bst_node* search(const Key& val) const;
  ~BST();
private:
  bst_node* root_ = nullptr;

  void clear_tree(bst_node* root);
  bst_node* find_min_node(bst_node* root) const;
  bst_node* insert_impl(bst_node*& root, const Key& val);
  bst_node* remove_impl(bst_node* root, const Key& val);
  bst_node* search_impl(bst_node* root, const Key& val) const;
};


template<typename Key>
typename BST<Key>::bst_node* BST<Key>::find_min_node(bst_node* const root) const{
  auto min = root;
  while (min && min->left) {
    min = min->left;
  }
  return min;
}


template <typename Key>
typename BST<Key>::bst_node* BST<Key>::insert(const Key& val) {
  return insert_impl(root_, val);
}


template <typename Key>
typename BST<Key>::bst_node* BST<Key>::insert_impl(bst_node*& root, const Key& val) {
  if (!root) {
    return root = new bst_node{val, nullptr, nullptr};
  }

  if (root->val > val) {
    root->left = insert_impl(root->left, val);
  } else {
    root->right = insert_impl(root->right, val);
  }

  return root;
}


template <typename Key>
typename BST<Key>::bst_node* BST<Key>::remove(const Key& val) {
  return root_ = remove_impl(root_, val);
}


template <typename Key>
typename BST<Key>::bst_node* BST<Key>::remove_impl(bst_node* root, const Key& val) {
  if (!root) {
    return root;
  }

  if (val < root->val) {
    root->left = remove_impl(root->left, val);
  } else if (val > root->val) {
    root->right = remove_impl(root->right, val);
  } else {
    if (!root->left && !root->right) {
      delete root;
      return nullptr;
    } else if (!root->left) {
      auto temp = root->right;
      delete root;
      return temp;
    } else if (!root->right) {
      auto temp = root->left;
      delete root;
      return temp;
    }

    auto min_node = find_min_node(root);
    root->val = min_node->val;
    root->right = remove_impl(root->right, min_node->val);
  }
  return root;
}


template <typename Key>
typename BST<Key>::bst_node* BST<Key>::search(const Key& val) const {
  return search_impl(root_, val);
}


template <typename Key>
typename BST<Key>::bst_node* BST<Key>::search_impl(bst_node* root, const Key& val) const {
  if (!root || root->val == val) {
    return root;
  }

  if (val > root->val) {
    return search_impl(root->right, val);
  } else {
    return search_impl(root->left, val);
  }
}


template <typename Key>
void BST<Key>::clear_tree(bst_node* root) {
  if (!root) {
    return;
  }

  clear_tree(root->left);
  clear_tree(root->right);
  delete root;
}


template <typename Key>
BST<Key>::~BST<Key>() {
  clear_tree(root_);
}

}

