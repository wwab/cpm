#include <iostream>
#include <cassert>
#include "WeinerInode.hpp"

WeinerInode::WeinerInode(WeinerInode* const parent,
                         bool text_node,
                         int edge_label_start,
                         int edge_label_length,
                         int path_label_start,
                         int path_label_length)
  : WeinerNode(parent,
               text_node,
               edge_label_start,
               edge_label_length,
               path_label_start,
               path_label_length) {
}

bool WeinerInode::checkChild(char c) {
  return children_.find(c) != children_.end();
}

int WeinerInode::getNumChildren() {
  return children_.size();
}

WeinerNode* WeinerInode::getChild(char c) {
  std::map<char, WeinerNode*>::iterator iter_child = children_.find(c);
  assert(iter_child != children_.end());
  assert(iter_child->second != NULL);
  return iter_child->second;
}

std::map<char, WeinerNode*> WeinerInode::getChildren() {
  return children_;
}

void WeinerInode::addChild(char c, WeinerNode* const node) {
  assert(children_.find(c) == children_.end());
  assert(node != NULL);
  children_[c] = node;
}

void WeinerInode::replaceChild(char c, WeinerNode* const node) {
  assert(children_.find(c) != children_.end());
  assert(node != NULL);
  children_[c] = node;
}

void WeinerInode::addIndicator(char c) {
  assert(!children_.empty()); // Indicator should only used for non-leaf nodes.
  indicator_.insert(c);
}

bool WeinerInode::checkIndicator(char c) {
  assert(!children_.empty()); // Indicator should only used for non-leaf nodes.
  return indicator_.find(c) != indicator_.end();
}

std::set<char> WeinerInode::getIndicatorVector() {
  return indicator_;
}


void WeinerInode::setIndicatorVector(std::set<char> indicator) {
  indicator_ = indicator;
}

void WeinerInode::addLink(char c, WeinerInode* const node) {
  assert(!children_.empty()); // Link should only used for non-leaf nodes.
  assert(node != NULL);
  links_[c] = node;
}

bool WeinerInode::checkLink(char c) {
  assert(!children_.empty()); // Link should only used for non-leaf nodes.
  return links_.find(c) != links_.end();
}

WeinerInode* WeinerInode::getLink(char c) {
  std::map<char, WeinerInode*>::iterator iter_link = links_.find(c);
  assert(iter_link != links_.end());
  assert(iter_link->second != NULL);
  return iter_link->second;
}

bool WeinerInode::isLeaf() {
  return false;
}
