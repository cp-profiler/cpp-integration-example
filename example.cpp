#include <iostream>
#include "cpp-integration/connector.hh"

int main() {

  using Profiling::Node;
  using Profiling::NodeStatus;

  Profiling::Connector c(6565);
  c.connect();

  c.restart(-1, "test example");

  /// First two nodes are constructed
  /// and sent in one line each

  // send root node
  c.sendNode(0, -1, -1, 2, NodeStatus::BRANCH, "root");

  // send left child
  c.sendNode(1, 0, 0, 0, NodeStatus::FAILED, "a");

  /// Third node is constructed with
  /// mandatory fields only, then
  /// an optional field (label) is specified separately
  /// and finally the resulting node is sent

  Node node(2, 0, 1, 0, NodeStatus::SOLVED);
  node.set_label("b");
  c.sendNode(node);

  c.done();
  c.disconnect();
}