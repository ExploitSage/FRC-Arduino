#include "Relay.h"

const Relay::Channel Relay::CHANNEL1(2,3);
const Relay::Channel Relay::CHANNEL2(4,5);
const Relay::Channel Relay::CHANNEL3(6,7);
const Relay::Channel Relay::CHANNEL4(8,9);
const Relay::Channel Relay::CHANNEL5(10,11);
const Relay::Channel Relay::CHANNEL6(12,13);

const Relay::Direction Relay::OFF(false, false);
const Relay::Direction Relay::FORWARD(true, false);
const Relay::Direction Relay::REVERSE(false, true);
const Relay::Direction Relay::ON(true, true);

//-------------------------------------------
Relay::Direction::Direction() { //default needed for whatever reason
	_a = false;
	_b = false;
}

Relay::Direction::Direction(bool a, bool b) {
	_a = a;
	_b = b;
}
bool Relay::Direction::get_a() {
	return _a;
}
bool Relay::Direction::get_b() {
	return _b;
}

bool Relay::Direction::compare(Relay::Direction direction) {
	if(direction.get_a() == _a && direction.get_b() == _b)
		return true;
	return false;
}
//-------------------------------------------
Relay::Channel::Channel() { //default needed for whatever reason
	_a = 0;
	_b = 0;
}

Relay::Channel::Channel(uint8_t a, uint8_t b) {
	_a = a;
	_b = b;
}
uint8_t Relay::Channel::get_a() {
	return _a;
}
uint8_t Relay::Channel::get_b() {
	return _b;
}
//-------------------------------------------

Relay::Relay() {
	_init = false;
}

void Relay::attach(Relay::Channel channel) {
	_channel = channel;

	pinMode(_channel.get_a(), OUTPUT);
	pinMode(_channel.get_b(), OUTPUT);
	digitalWrite(_channel.get_a(), LOW);
	digitalWrite(_channel.get_b(), LOW);
	
	set(Relay::OFF);
	_init = true;
}

void Relay::set(Relay::Direction direction) {
	if(_init) {
		_direction = direction;
		digitalWrite(_channel.get_a(), _direction.get_a());
		digitalWrite(_channel.get_b(), _direction.get_b());
	}
}

Relay::Direction Relay::get() {
	return _direction;
}
Relay::Channel Relay::get_channel() {
	return _channel;
}

void Relay::off() {
	set(Relay::OFF);
}
void Relay::forward() {
	set(Relay::FORWARD);
}
void Relay::reverse() {
	set(Relay::REVERSE);
}