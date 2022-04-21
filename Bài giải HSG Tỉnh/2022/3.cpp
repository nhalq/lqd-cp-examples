#include <bits/stdc++.h>

#define LEFT	1
#define RIGHT	2

int main(/* const int argc, const char** argv */) {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int num_shafts, num_weights;
	std::cin >> num_shafts >> num_weights;

	std::vector<int> shafts(num_shafts);
	for (auto& shaft: shafts)
		std::cin >> shaft;

	std::vector<int> weights(num_weights);
	for (auto& weight: weights)
		std::cin >> weight;

	// Power of 3: 3⁰, 3¹, 3², ..., 3ⁿ
	// Dùng để thay thế cho 2ⁿ [hay (1 << n)] trong cách duyệt nhị phân
	// 1 ≤ num_weights ≤ 14
	// 3¹⁴ = 4782969 ⇒ int32 (số nguyên 32 bit)
	std::vector<int> power_of_3(num_weights + 1, 1);
	for (int i = 1; i <= num_weights; ++i)
		power_of_3[i] = power_of_3[i - 1] * 3;

	std::set<int> balances;

	// Duyệt qua tất cả cách trường hợp
	for (int mask = 0; mask < power_of_3[num_weights]; ++mask) {
		// Quy ước: (0) - Không chọn
		//          (1) - Tạ sẽ được bỏ vào bên trái
		//          (2) - Tạ sẽ được bỏ vào bên phải
		// "total" biểu diễn cân nặng tạ theo quy ước trên.
		std::vector<int> total(3);
		for (int i = 0; i < num_weights; ++i) {
			// Để dễ hình dung công thức bên dưới ta sẽ quay lại hệ cơ số 10
			// Bài toán: Tìm chữ số hàng trăm của số 12807
			// Dễ dàng nhận thấy đó là số 8.
			// Để lấy được số 8 ta thực hiện phép chia
			// 12807 / 100 = 128
			// Sau đó thực hiện phép mod
			// 128 % 10 = 8
			// Từ quan sát trên ta nhận thấy nếu muốn lấy số thứ i ở hệ cơ số 10,
			// ta áp dụng công thứ: (n / 10^i) % 10
			// Áp dụng cho hệ cơ số 3: (n / 3^i) % 3
			total[(mask / power_of_3[i]) % 3] += weights[i];

			/** Advanced
			 *
			 * Thông thường ở hệ cơ số 2 ta hay dùng: n & (2^i) [hoặc n & (1 << i)]
			 * Các bạn cũng có thể dùng cách như trên nhưng ở hệ cơ số 2
			 * chỉ cho ra 2 kết quả là 0 hoặc 1 (false hoặc true)
			 * Do đó việc tính toán nhiều làm giảm "hiệu năng" lời giải,
			 * nên ta sẽ quy bài toán về bài toán mà lời giải của nó
			 * chỉ cho ra kết quả là 0 hoặc "một giá trị khác 0"
			 * để ta có thể sử dụng ít phép toán hơn.
			 * //\\// //=// //=\\ */
		}

		if (total[LEFT] == total[RIGHT]) {
			// Có thể viết bằng các cách khác như:
			//   total[LEFT] + total[RIGHT]
			//   2 * total[.] (vì cân nặng 2 bên bằng nhau)
			//   nhưng sử dụng total[.] << 1 để tối ưu các phép tính toán
			balances.insert(total[LEFT] << 1);

			// Có thể chỉ insert total[.] sau đó double lúc kết hợp với shaft
			// để tăng hiệu năng cho lời giải
		}
	}

	std::set<int> expects;
	for (const auto& shaft: shafts) {
		for (const auto& weight: balances) {
			expects.insert(shaft + weight);
		}
	}

	for (const auto& weight: expects)
		std::cout << weight << '\n';
	return EXIT_SUCCESS;
}

/** Facts
 *
 * Lý do không nên dùng đệ quy thay cho cách duyệt kiểu này:
 * - Tránh được stack overflow
 * - Tránh được tình trạng dead-loop (infinity-loop)
 * //\\// //=// //=\\ */
