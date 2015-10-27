#include "cpp-integration/connector.hh"

int main() {

  using Profiling::Node;
  using Profiling::NodeStatus;

  /// Instantiate a Connector with 6565 as port
  Profiling::Connector c(6565);
  c.connect();

  /// Starting a new tree and specifying restart_id (starting from 0)
  c.restart("restarts example", 0);

  c.createNode(0, -1, -1, 2, NodeStatus::BRANCH).set_label("root-1").send();
  c.createNode(1, 0, 0, 0, NodeStatus::FAILED).set_label("a").send();
  c.createNode(2, 0, 1, 0, NodeStatus::SOLVED).set_label("b").send();

  /// Initiate restart #1
  /// Note that setting corresponding restart_id is required for each node
  c.restart("restarts example", 1);
  c.createNode(0, -1, -1, 2, NodeStatus::BRANCH).set_label("root-2").set_restart_id(1).send();
  c.createNode(1, 0, 0, 0, NodeStatus::FAILED).set_label("c").set_restart_id(1).send();
  c.createNode(2, 0, 1, 0, NodeStatus::SOLVED).set_label("d").set_restart_id(1).send();

  /// Initiate restart #2
  c.restart("restarts example", 2);
  c.createNode(0, -1, -1, 2, NodeStatus::BRANCH).set_label("root-3").set_restart_id(2).send();
  c.createNode(1, 0, 0, 0, NodeStatus::FAILED).set_label("e").set_restart_id(2).send();
  c.createNode(2, 0, 1, 2, NodeStatus::BRANCH).set_label("f").set_restart_id(2).send();
  c.createNode(3, 2, 0, 0, NodeStatus::SOLVED).set_label("g").set_restart_id(2).send();
  c.createNode(4, 2, 1, 0, NodeStatus::FAILED).set_label("h").set_restart_id(2).send();

  c.done();
  c.disconnect();
}