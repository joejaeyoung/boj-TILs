/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2852                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2852                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 14:19:49 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>

using namespace std;

int n;
int team, pteam;
int score, pscore;
int m_1, s_1;
int m_2, s_2;

int main() {
	scanf("%d", &n);
	int m = 48, s = 0;
	int m_t, s_t;
	int idx = -1;


	do {
		++idx;
		scanf("%d %d:%d", &team, &m_t, &s_t);
		if (team == 1) score++;
		else score--;

		//+ -> 0 1팀 승리 끝
		if (pscore > 0 && score == 0) {
			m_1 += m_t - m;
			s_1 += s_t - s;
			pteam = -1;
		}
		//- -> 0 2팀 승리 끝
		else if (pscore < 0 && score == 0) {
			m_2 += m_t - m;
			s_2 += s_t - s;
			pteam = -1;
		}
		//1팀 승리 시작
		else if (score > 0 && pscore == 0) {
			m = m_t; s = s_t;
			pteam = 1;
		}
		//2팀 승리 시작
		else if (score < 0 && pscore == 0) {
			m = m_t; s = s_t;
			pteam = 2;
		}
		pscore = score;
	} while (--n);

	if (score > 0 && pteam == 1) {
		m_1 += 48 - m;
		s_1 -= s;
	}
	else if (score < 0 && pteam == 2) {
		m_2 += 48 - m;
		s_2 -= s;
	}

	while(m_1 < 0) {
		m_1 += 1;
		s_1 -= 60;
	}

	while(m_2 < 0) {
		m_2 += 1;
		s_2 -= 60;
	}

	while(s_1 < 0) {
		s_1 += 60;
		m_1 -= 1;
	}

	while(s_2 < 0) {
		s_2 += 60;
		m_2 -= 1;
	}

	while(s_1 >= 60) {
		s_1 -= 60;
		m_1 += 1;
	}
	while(s_2 >= 60) {
		s_2 -= 60;
		m_2 += 1;
	}
	
	printf("%02d:%02d\n", m_1, s_1);
	printf("%02d:%02d\n", m_2, s_2);
}