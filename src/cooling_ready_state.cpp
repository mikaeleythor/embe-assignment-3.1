#include <context.h>
#include <cooling_ready_state.h>
#include <cooling_running_state.h>

void Cooling_ready_state::on_fan_running() {
  this->context_->transition_to(new Cooling_running_state);
}

void Cooling_ready_state::on_do() {};

void Cooling_ready_state::on_entry() {};

void Cooling_ready_state::on_exit() {};

void Cooling_ready_state::on_ok() {};

void Cooling_ready_state::on_failure() {};

void Cooling_ready_state::on_too_hot() {};

void Cooling_ready_state::on_too_cold() {};

void Cooling_ready_state::on_compressor_running() {};

void Cooling_ready_state::on_cleared() {};

String Cooling_ready_state::get_name() { return this->name; }
