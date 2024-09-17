#include <context.h>
#include <failure_state.h>
#include <idle_state.h>

void Failure_state::on_cleared() {
  this->context_->transition_to(new Idle_state);
}

void Failure_state::on_do() {};

void Failure_state::on_entry() {};

void Failure_state::on_exit() {};

void Failure_state::on_ok() {};

void Failure_state::on_failure() {};

void Failure_state::on_too_hot() {};

void Failure_state::on_too_cold() {};

void Failure_state::on_compressor_running() {};

void Failure_state::on_fan_running() {};

String Failure_state::get_name() { return this->name; }
