#pragma once
#include <string>
#include <fstream>
namespace Kiwii {
	class Deep {
	protected:
		std::string _name;
		bool _pointer;
	public:
		virtual void info(std::string name);

		std::string name() {
			return _name;
		}
		void name(std::string namee) {
			_name = namee;
		}
	};

}
