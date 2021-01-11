// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/17677?language=javascript
/*
    다 풀고나서 든 생각인데 어차피 합집합과 교집합의 길이만 알면 되기 때문에
    굳이 배열에 원소를 추가하지 않고 집합의 길이만 구해도 됐을거라는 생각이 든다.
    하지만 귀찮으니까 수정은 하지 않겠음..
 */
function solution(str1, str2) {
	// 대소문자를 구분하지 않으므로 str1과 str2를 모두 소문자로 변환한다.
	const newStr1 = str1.toLowerCase();
	const newStr2 = str2.toLowerCase();
	const str1Length = newStr1.length,
		str2Length = newStr2.length;
	// 문자열에서 알파벳만을 찾을때 사용할 변수
	const reg = /^[a-z]+$/;
	let answer = 0,
		intersectionLength,
		unionLength,
		arr1Length;
	// 각 문자열을 두글자씩 끊은 원소들의 집합을 저장할 배열
	let arr1 = [],
		arr2 = [];
	// 교집합과 전체집합을 저장할 배열
	let intersection = [],
		total = [];

	for (let i = 0; i < str1Length - 1; i++) {
		// 문자열을 두글자씩 끊는다
		const temp = newStr1.substr(i, 2);
		// 현재 문자열에 알파벳만 들어있다면 배열에 저장함
		if (reg.test(temp)) {
			arr1.push(temp);
		}
	}
	for (let i = 0; i < str2Length - 1; i++) {
		// 문자열을 두글자씩 끊는다
		const temp = newStr2.substr(i, 2);
		// 현재 문자열에 알파벳만 들어있다면 배열에 저장함
		if (reg.test(temp)) {
			arr2.push(temp);
		}
	}
	// 전체 집합 저장
	total = arr1.concat(arr2);
	// arr1배열의 길이 저장
	arr1Length = arr1.length;

	for (let i = 0; i < arr1Length; i++) {
		const index = arr2.indexOf(arr1[i]);
		// 두배열 사이에 중복되는 원소가 있다면
		if (index >= 0) {
			// 교집합 배열에 해당 원소 추가
			intersection.push(arr1[i]);
			// arr2에서 해당 원소를 제거
			arr2.splice(index, 1);
		}
	}
	// 교집합 길이 저장
	intersectionLength = intersection.length;
	// 합집합은 전체집합 - 교집합이다.
	unionLength = total.length - intersectionLength;
	// 합집합이 공집합일 경우에는 arr1과 arr2가 모두 공집합이라는 얘기이므로
	// 문제에 제시된것처럼 정답은 1이다.
	if (unionLength == 0) {
		answer = 65536;
	}
	// 교집합이 없을때는 정답은 0이다.
	else if (intersectionLength == 0) {
		answer = 0;
	}
	// 문제에 제시된대로 교집합을 합집합으로 나누고 65546을 곱함
	else {
		answer = Math.floor((intersectionLength / unionLength) * 65536);
	}

	return answer;
}
