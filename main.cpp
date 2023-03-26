#include <iostream>

using namespace std;

using ll = long long;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	ll m_{};
	ll n_{};
	ll x_{};
	ll y_{};

	ll ans_{};

public:
	void input() {
		cin >> m_ >> n_ >> x_ >> y_;
	}

	void solve() {
		ans_ = -1;

		auto lim = lcm(m_, n_);
		for (auto x = x_; x <= lim; x += m_) {
			auto ny = x % n_;
			if (0 == ny) {
				ny = n_;
			}

			if (ny == y_) {
				ans_ = x;
				break;
			}
		}

		if (lim < ans_) {
			ans_ = -1;
		}
	}

	void output() const noexcept {
		cout << ans_ << '\n';
	}

private:
	ll gcd(ll a, ll b) const {
		if (a < b) {
			return gcd(b, a);
		}

		if (0 == b) {
			return a;
		}

		return gcd(b, a % b);
	}

	ll lcm(ll a, ll b) const {
		return a * b / gcd(a, b);
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t; cin >> t;
	while (0 < (t--)) {
		auto s = solution{};
		s.input();
		s.solve();
		s.output();
	}

	return 0;
}