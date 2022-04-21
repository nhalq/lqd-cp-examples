#include <bits/stdc++.h>

// Theo mô tả đề bài, điểm là các số thực nằm trong "đoạn" [0.0000; 10.0000]
const int SCORE_MIN    = 000000;
const int SCORE_MAX    = 100000;
const int SCORE_OFFSET = SCORE_MAX - SCORE_MIN + 1;

/**
 * Dùng để đọc các số như yêu cầu bài toán
 * Ví dụ: 1.2871
 *
 * Lưu ý: hàm này không đúng nếu a[i] và b[i] có dạng 1 số nguyên
 * Ví dụ: 8
 * Do đó cần viết lại một xíu để chính xác hơn
 * [có thể thêm fast scan để tăng hiệu năng (lưu ý fast scan cả n và m)]
 */
int weird_scan() {
	int a, b;
	char ignore;
	std::cin >> a >> ignore >> b;
	return 10000 * a + b;
}

int main(/* const int argc, const char** argv */) {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a_scores(n);
	for (auto& score: a_scores)
		score = weird_scan();

	std::vector<int> b_scores(m);
	for (auto& score: b_scores)
		score = weird_scan();

	// max(n, m) ≤ 10⁶
	// ⇒ counts[i] ≤ 10⁶
	// ⇒ int32 (số nguyên 32 bit)
	std::vector<int> a_counts(SCORE_OFFSET);
	for (const auto& score: a_scores)
		++a_counts[score];

	std::vector<int> b_counts(SCORE_OFFSET);
	for (const auto& score: b_scores)
		++b_counts[score];

	// 1 ≤ n, m ≤ 10⁶
	// Kết quả không có quá n × m = 10¹² cặp
	// ⇒ int64 (số nguyên 64 bit)
	int64_t number_scores = 0;
	// (hoặc)
	// long long number_scores = 0;
	for (int i = SCORE_MIN; i <= SCORE_MAX; ++i)
		number_scores += a_counts[i] * b_counts[i]; // Bắt cặp

	std::cout << number_scores << std::endl;
	return EXIT_SUCCESS;
}

/** Tips
 *
 * Có thể thay đổi hằng số SCORE_MIN, SCORE_MAX
 * bằng score_min, score_max (và tính score_offset)
 * của dữ liệu đầu vào để tăng hiệu năng bài toán
 */
