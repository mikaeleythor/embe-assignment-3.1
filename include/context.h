#ifndef CONTEXT_H
#define CONTEXT_H
#include <state.h>
class Context {
  /**
   * @var State A reference to the current state of the Context.
   */

private:
  State *state_;

public:
  Context(State *state) : state_(nullptr) { this->transition_to(state); }

  ~Context() { delete state_; }

  /**
   * The Context allows changing the State object at runtime.
   */

  void transition_to(State *state) {
    Serial.println("State changed to " + state->get_name());
    if (this->state_ != nullptr) {
      this->state_->on_exit();
      delete this->state_;
    }

    this->state_ = state;

    this->state_->set_context(this);

    this->state_->on_entry();
  }

  /**
   * The Context delegates part of its behavior to the current State object.
   */

  void do_work() { this->state_->on_do(); }

  void ok() { this->state_->on_ok(); };

  void failure() { this->state_->on_failure(); };

  void too_hot() { this->state_->on_too_hot(); };

  void too_cold() { this->state_->on_too_cold(); };

  void compressor_running() { this->state_->on_compressor_running(); };

  void fan_running() { this->state_->on_fan_running(); };

  void cleared() { this->state_->on_cleared(); };
};
#endif // CONTEXT_H
