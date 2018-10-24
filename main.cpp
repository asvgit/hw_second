#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <memory>
#include "lib.h"

int main() {
    try {
        std::vector<StringVector> ip_pool;

        for(std::string line; std::getline(std::cin, line);) {
            StringVector v = str::split(line, '\t');
            ip_pool.push_back(str::split(v.at(0), '.'));
        }

		std::sort(ip_pool.begin(), ip_pool.end(), [](const auto &a, const auto &b) {
			for(int i = 0; i < 4; ++i) {
				const int first = std::stoi(a[i]), second = std::stoi(b[i]);
				if (first == second)
					continue;
				return first > second;
			}
			return true;
		});

		auto print_ip = [](const StringVector &ip) {
            for(const auto &ip_part : ip) {
                if (ip_part != ip[0]) {
                    std::cout << ".";
                }
                std::cout << ip_part;
            }
            std::cout << std::endl;
		};

        for(const auto &ip : ip_pool) {
			print_ip(ip);
        }

		using filter_type = std::vector<std::shared_ptr<StringVector>>;
		// filter_1 filter_46_70 filter_any_46; 
		std::vector<filter_type> filters = {{}, {}, {}};
		for (const auto &ip : ip_pool) {
			if (ip.front() == "1") {
				filters[0].push_back(std::make_shared<StringVector>(ip));
			} else if (ip[0] == "46" && ip[1] == "70") {
				filters[1].push_back(std::make_shared<StringVector>(ip));
			}
			if (std::find(ip.cbegin(), ip.cend(), "46") != ip.end()) {
				filters[2].push_back(std::make_shared<StringVector>(ip));
			}
		}

		std::cout << std::endl;
		for (const auto &f : filters) {
			for (const auto &item : f) {
				print_ip(*item);
			}
			std::cout << std::endl;
		}
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
