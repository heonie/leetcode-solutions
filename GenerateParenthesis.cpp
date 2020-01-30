class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> comb;
		generate(comb, "", n, 0);
		return comb;
	}
	void generate(vector<string>& comb, string current, int n, int openCount) {
		if (n == 0 && openCount == 0) {
			comb.push_back(current);
			return;
		}
		if (openCount > 0) {
			generate(comb, current + ")", n - 1, openCount - 1);
		}
		if (n > openCount) {
			generate(comb, current + "(", n, openCount + 1);
		}
	}
};
