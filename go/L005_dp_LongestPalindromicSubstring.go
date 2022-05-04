package leetcode

import "fmt"

func longestPalindrome(s string) string {
	n := len(s)
	var j int
	var ans string
	var dp = make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
	}
	for k := 0; k < n; k++ {
		for i := 0; i+k < n; i++ {
			j = i + k
			if k == 0 {
				dp[i][j] = true
			} else if k == 1 {
				dp[i][j] = (s[i] == s[j])
			} else {
				dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]))
			}
			if dp[i][j] && (k+1) > len(ans) {
				ans = s[i : i+k+1]
			}
		}
	}
	return ans
}

func main() {
	str := "niin"
	ans := longestPalindrome(str)
	fmt.Printf(ans)
}
