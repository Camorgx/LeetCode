#pragma once

#include "CommonStructure.h"
#include <string>

namespace Sept2022 {
	using std::vector;
	using std::string;

	class CrawlerLogFolder : public ITestable {
		class Solution {
		public:
			int minOperations(vector<string>& logs);
		};
	public:
		void run_test() override;
	};
}