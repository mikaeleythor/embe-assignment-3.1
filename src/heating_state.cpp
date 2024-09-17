#include <context.h>
#include <failure_state.h>
#include <heating_state.h>
#include <idle_state.h>

void Heating_state::on_ok() { this->context_->transition_to(new Idle_state); }

void Heating_state::on_failure() {
  this->context_->transition_to(new Failure_state);
}

void Heating_state::on_do() {};

void Heating_state::on_entry() {};

void Heating_state::on_exit() {};

void Heating_state::on_too_hot() {};

void Heating_state::on_too_cold() {};

void Heating_state::on_compressor_running() {};

void Heating_state::on_fan_running() {};

void Heating_state::on_cleared() {};

String Heating_state::get_name() { return this->name; }
