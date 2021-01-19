//문제링크: https://programmers.co.kr/learn/courses/30/lessons/17680?language=javascript
function solution(cacheSize, cities) {
	let answer = 0;
	// 캐시 배열
	let cache = [];
	// 캐시크기가 0일 경우에는 캐시배열에 아무것도 담을 수 없기 때문에
	// 캐시 미스가 cities배열의 길이만큼 일어나게 된다.
	if (cacheSize === 0) {
		return cities.length * 5;
	}

	cities.forEach((city) => {
		// 도시 이름은 대소무자를 구분하지 않기 때문에 모두 소문자로 바꿔준다.
		city = city.toLowerCase();
		// cache배열에서 city와 같은 이름을 가진 원소의 인덱스를 찾는다.
		const index = cache.indexOf(city);
		// cache배열에 city와 이름이 같은 원소가 이미 들어있을 경우
		if (index >= 0) {
			// 캐시히트가 일어났으므로 answer에 1을 더한다
			answer += 1;
			// cache에서 해당 원소를 제거한다.
			cache.splice(index, 1);
		}
		// cache배열에 city가 없을 경우
		else {
			// 캐시가 꽉찼다면
			if (cache.length === cacheSize) {
				// LRU알고리즘에 따라 가장 오래된 원소를 제거한다.
				cache.splice(0, 1);
			}
			// 캐시미스가 일어났으므로 answer에 5를 더한다.
			answer += 5;
		}
		// cache배열에 city를 추가한다.
		cache.push(city);
	});

	return answer;
}
