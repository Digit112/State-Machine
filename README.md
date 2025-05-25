# State-Machine

A state machine, or to be more precise a finite state machine in this case, is a kind of automaton with a finitie number of distinct states it can be in. States are transitioned between based on the inputs supplied.

The underlying structure supporting such a state machine is the directed graph. The vertices (internally, nodes) of a graph constitute its states and the edges represent transitions between them.
It follows that the edges are therefore associated with predicates whose boolean evaluation determines whether the transition is valid, and also potentially with callback functions for handlers which are called upon a certain transition.

The core of the repository is the `directed_graph` class which facilitates the creation and modification of directed graphs, as well as the association of arbitrary (templated) data with them each.

The `state_machine` class will use a `directed_graph<state_machine::state, state_machine::transition>` to facilitate its operations. The `state` class will consist of an optional name and callbacks `on_enter()` and `on_exit()` while
the `transition` class will consist of a `state_machine::predicate` operating on a user-supplied data structure to determine whether to follow the edge, and a callback `on_follow()`.
