#ifndef ARDUINO_FLOTILLA_MODULEMOTION_H
#define ARDUINO_FLOTILLA_MODULEMOTION_H

#include <Arduino.h>
#include "module.h"
#include "timeout.h"
#include "averagevalue.h"

template <typename value_t>
struct Vector {
	value_t x, y, z;

	bool operator==(Vector& that) {
		return x == that.x && y == that.y && z == that.z;
	}

	bool operator!=(Vector& that) {
		return !(*this == that);
	}
};

class ModuleMotion : public Module {
  private:
	Vector<int16_t> m_prevAccel;
	Vector<int16_t> m_prevMag;
	Vector<AverageValue<int32_t, int16_t>> m_accel;
	Vector<AverageValue<int32_t, int16_t>> m_mag;
	TimeOut m_timeout;

  protected:
	virtual void GetState(Vector<int16_t>& accel, Vector<int16_t>& mag) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "motion";
	}

	virtual void Update(Stream* stream);
};

#endif