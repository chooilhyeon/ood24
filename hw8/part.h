#ifndef _PART_H
#define _PART_H

#include <string>

class Part {
	public:
	explicit Part(std::string factory_name);
	virtual std::string GetInfo() const = 0;
	std::string factory_name() const;
	virtual ~Part() = 0;
	private:
	const std::string factory_name_;
	};

#endif  // _PART_H
