#include <iostream>
#include <map>

int main() {
	std::map<int, std::string> m;

	m.insert(std::pair<int, std::string>(40, "me"));
	m.insert(std::pair<int, std::string>(35, "show"));
	m.insert(std::make_pair(10, "docks"));

	std::map<int, std::string>::iterator it;	// 반복자 선언
	for (it = m.begin(); it != m.end(); it++) {
		std::cout << " [ " << it->first << ": " << it->second << " ] " << std::endl;
		std::cout << " [ " << (*it).first << ": " << (*it).second << " ] " << std::endl;
	}
	std::cout << std::endl;


	/* operator[] */
	std::map<int, std::string>m2;
	m2[1] = "one";
	m2[2] = "two";

	for (auto& e : m2) {
		std::cout << e.first << ": " << e.second << std::endl;
	}
	std::cout << std::endl;


	std::map<std::string, int> m3;
	m3.insert({ "one", 10 });
	m3.insert({ "two", 20 });

	for (auto& p : m3) {
		std::cout << "type: " << typeid(p).name() << p.first << std::endl;
	}


	return 0;
}