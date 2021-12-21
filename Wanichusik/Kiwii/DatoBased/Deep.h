#pragma once
#include <string>
#include <fstream>
namespace Kiwii {
	class Deep {
	protected:
		std::string _name;
		bool _pointer;
	public:
		virtual void _info_r(std::string _name_r);

		std::string _name_r() {
			return _name;
		}
		void _name_r(std::string namee) {
			_name = namee;
		}
	};

}
