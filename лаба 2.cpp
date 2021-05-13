#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <locale>
#include <cstdlib>
#include <string>
#include <sstream>

class Time
{
public:
	typedef unsigned short ushort;
	Time(ushort hs, ushort ms, ushort ss)
	{
		set_time(hs, ms, ss);
	}

	explicit Time(size_t ss = 0)
	{
		set_time(ss);
	}

	explicit Time(std::string const& stime)
	{
		set_time(stime);
	}

	void set_time(ushort hs, ushort ms, ushort ss)
	{
		_hs = hs;
		_ms = ms;
		_ss = ss;
		check();
	}

	void set_time(size_t ss)
	{
		_hs = ss / 3600;
		_ms = (ss % 3600) / 60;
		_ss = (ss % 3600) % 60;
		check();
	}

	void set_time(std::string const& stime) // "23:59:59"
	{
		std::stringstream sstr;
		for (auto const& val : stime)
			sstr << (val == ':' ? ' ' : val);
		sstr >> _hs >> _ms >> _ss;
		if (!sstr || !sstr.eof())
			throw std::runtime_error("Time::set_time: !sstr || !sstr.eof()");
		check();
	}

	friend std::ostream& operator<<(std::ostream& ost, Time const& rhs)
	{
		return ost << rhs._hs << ':' << rhs._ms << ':' << rhs._ss;
	}

	operator std::string() const
	{
		std::stringstream sstr;
		sstr << _hs << ':' << _ms << ':' << _ss;
		return sstr.str();
	}

private:
	ushort _hs, _ms, _ss;
	void check() const
	{
		if (_hs >= 24 || _ms >= 60 || _ss >= 60)
			throw std::runtime_error("Time::check: _hs >= 24  || _ms >= 60 || _ss >= 60");
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Time hms1("23:45:40"), hms2(23 * 3600 + 45 * 60 + 41), hms3(23, 45, 42);
	std::string shms3 = hms3;
	std::cout << hms1 << '\n' << hms2 << '\n' << shms3 << "\n\n";
	system("pause");
	return 0;
}