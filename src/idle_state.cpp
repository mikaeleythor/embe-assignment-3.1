#include "cooling_ready_state.h"
#include <context.h>
#include <cooling_running_state.h>
#include <cooling_startup_state.h>
#include <heating_state.h>
#include <idle_state.h>

void Idle_state::on_too_cold() {
  this->context_->transition_to(new Heating_state);
}

void Idle_state::on_too_hot() {
  this->context_->transition_to(new Cooling_startup_state);
  _delay_ms(2000);
  this->context_->compressor_running();
  _delay_ms(3000);
  this->context_->fan_running();
}

void Idle_state::on_do() {};

void Idle_state::on_entry() {};

void Idle_state::on_exit() {};

void Idle_state::on_ok() {};

void Idle_state::on_failure() {};

void Idle_state::on_compressor_running() {};

void Idle_state::on_fan_running() {};

void Idle_state::on_cleared() {};

String Idle_state::get_name() { return this->name; }
