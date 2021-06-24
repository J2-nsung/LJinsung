"""

알파벳(A~Z)을 0~25까지 index를 부여해주고 26*N으로 최대로 표현할 수 있는 가치를 구해준다.
조건에 맞는 문자열을 만들 때, 사전 순으로 가장 앞서는 것을 출력해야 하기 때문에 우선 A를 넣어본다.
이 때, (남은 가치(diff)-표현해야 할 남은 가치(X))가 26보다 작거나 같으면 해당 위치를 A로 넣었을 경우
가치를 표현할 수 없기 때문에 26-(diff-X)번째 알파벳을 넣어주고 남은 길이는 모두 Z로 채워준다.

첫 번째 예제의 경우, 문자열의 총 길이가 6이고 가치는 64이다.
3번째 문자를 채워야 할 경우부터 보자. 앞서 완성된 문자열은 'A A _ _ _ _'
현재 위치를 포함하여 4개의 문자로 최대 26*4 = 104의 가치를 표현할 수 있고, 우리가 표현해야 할 가치는 64-2 = 62가 남았다.
현재 위치에서 A를 넣을 경우 남은 가치는 61이고 나머지 3개의 문자로는 최대 26*3 = 78을 표현할 수 있으므로 'A'를 넣어준다.
앞서 완성 된 문자열은 'A A A _ _ _'

4번째 문자를 A로 채운다면 남은 가치는 60이고 나머지 2개의 문자로는 52까지밖에 표현하지 못하므로 A를 넣을 수 없다.
남은 가치를 표현 가능하고 사전 순으로 가장 앞에 있는 알파벳을 넣어주려면 26-((26*3)-61)번째 알파벳을 넣어주어야 한다.
26-((26*3)-61) = 9. 9번째 문자는 'I'이므로 현재 위치에 'I'를 넣어주고 나머지 문자들은 'Z'로 채워준다.
완성 된 문자열은 'AAAIZZ'

"""
import string

alpha = [c for c in string.ascii_uppercase]
alpha.insert(0, "0")

N, X = map(int, input().split())
answer = str()
if (26 * N < X) or (X < N):
    print("!")

else:
    while X:
        diff = 26 * N  # 매 자리마다 채워야 할 문자열의 남은 길이로 표현할 수 있는 최대 가치를 구해준다.
        if diff - X <= 26:  # 최대로 표현 가능한 가치보다 앞으로 표현해야 할 가치가 큰 경우 A를 넣을 수 없다.
            answer += alpha[(26 - (diff - X))]
            break
        else: # A를 넣을 수 있는 경우 A를 넣는다.
            answer += "A"
            X -= 1
        N -= 1
    print(answer + "Z" * (N - 1)) # 남아있는 길이를 Z로 채워준다.