#include<string>
#include<vector>
#include "Zigzag.h"

std::string Solution5::zigzagConvert(std::string s, int numRows) {
	if (numRows == 1 || numRows >= s.length()) return s;

	std::vector<std::string> rows(numRows);
	int currentRow = 0;
	bool goingDown = false;

	for (char c : s) {
		rows[currentRow] += c;

		// Đổi hướng khi chạm đỉnh hoặc đáy
		if (currentRow == 0 || currentRow == numRows - 1)
			goingDown = !goingDown;

		// Di chuyển lên hoặc xuống
		currentRow += goingDown ? 1 : -1;
	}
	// Gộp tất cả hàng lại
	std::string result;
	for (const std::string& row : rows)
		result += row;

	return result;
}