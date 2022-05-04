package LeetCode

func longestValidParentheses(s string) int {
	/*
		1.分析: dp[i]表示当前i为结尾的最长子串的长度
		2.比如dp[i] = 2,说明dp[i-1] 到dp[i]可以满足要求
		3.由此可以知道,s[i]='('肯定不符合，即为dp[i]=0
		4.s[i]=')',需要分情况讨论,
		5.如果s[i-1]='(',直接dp[i] +=2(因为初始化为0)
		6.如果s[i-1]=')'话,还需要判断s[i-dp[i-1]-1]的值
		  i-dp[i-1]-1 =k
		7.	0 1 2 3
		8.	( ( ) )
		9.  k     i
	*/
	len1 := len(s)
	var maxlen int = 0
	var dp = make([]int, len1)
	for i := 1; i < len1; i++ {
		if s[i] == ')' {
			if s[i-1] == '(' {
				if i >= 2 {
					dp[i] = dp[i-2] + 2
				} else {
					dp[i] += 2
				}
			} else {
				if i-dp[i-1]-1 > 0 && s[i-dp[i-1]-1] == '(' {
					dp[i] = dp[i-1] + 2
					if (i - dp[i-1] - 2) >= 0 {
						dp[i] = dp[i] + dp[i-dp[i-1]-2]
					}
				}
			}
		}
		if dp[i] > maxlen {
			maxlen = dp[i]
		}
	}
	return maxlen
}
