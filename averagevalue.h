#ifndef ARDUINO_FLOTILLA_AVERAGE_VALUE_H
#define ARDUINO_FLOTILLA_AVERAGE_VALUE_H

template <typename total_t, typename value_t>
class AverageValue {
  private:
	value_t m_count;
	total_t m_total;

  public:
	AverageValue() : m_count(0), m_total(0) {
	}

	void reset() {
		m_count = 0;
		m_total = 0;
	}

	value_t value() {
		if (m_count == 0) {
			return 0;
		}
		return value_t(m_total / m_count);
	}

	void addValue(value_t val) {
		m_count++;
		m_total += val;
	}
};

#endif