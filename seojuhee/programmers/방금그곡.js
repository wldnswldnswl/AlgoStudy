// 문제링크: https://programmers.co.kr/learn/courses/30/lessons/17683?language=javascript

// 노래재생시간을 계산하는 함수
function getPlayTime(start, end) {
	// const endHour = end[0] === '00' ? 24 : Number(end[0]);
	// return (endHour * 60 + Number(end[1])) - (Number(start[0]) * 60 + Number(start[1]));
	// 노래재생이 끝난 시각이 '00:00'일때를 처리해줘야하는데 그러면 4번, 11번 테케가 자꾸 틀림
	// 그래서 처리안하도록함
	return (Number(end[0]) - Number(start[0])) * 60 + (Number(end[1]) - Number(start[1]));
}
// 원래 멜로디 문자열에서 #이 붙은 음들을 소문자로 변환하여 반환하는 함수
function getMelody(prevMelody) {
	const length = prevMelody.length;
	// 반환할 멜로디 문자열
	let curMelody = '';
	for (let i = 0; i < length; i++) {
		const current = prevMelody[i];
		// 현재 원소가 마지막 원소이거나 다음 원소가 #이 아닐경우
		if (prevMelody[i + 1] !== '#' || i === length - 1) {
			// 현재 원소를 저장
			curMelody += current;
		}
		// 현재 원소가 마지막 원소가 아니면서 다음 원소가 #일 경우
		else {
			// 현재 원소를 소문자로 변환하여 저장
			curMelody += current.toLowerCase();
			// i를 1 증가시킴
			i++;
		}
	}
	// 변환된 멜로디 반환
	return curMelody;
}

function solution(m, musicinfos) {
	let answer = '',
		mLength;
	// 곡의 정보들을 쪼개서 저장할 배열과 조건이 일치하는 곡의 정보를 담을 배열
	let musicInfoSplitArr = [],
		correctArr = [];

	musicinfos.forEach((musicinfo) => {
		const temp = musicinfo.split(',');
		const start = temp[0].split(':');
		const end = temp[1].split(':');
		// 노래 재생 시간을 저장
		const playTime = getPlayTime(start, end);
		// 노래재생시간, 노래제목, 변환된 악보를 배열에 저장
		musicInfoSplitArr.push([playTime, temp[2], getMelody(temp[3])]);
	});
	// 입력받은 멜로디도 변환함
	m = getMelody(m);
	mLength = m.length;

	musicInfoSplitArr.forEach((musicInfoSplit) => {
		const playTime = musicInfoSplit[0];
		const music = musicInfoSplit[2];
		const musiclength = music.length;
		let longMusic = '',
			melody = m;
		// 노래가 재생된 시간만큼 악보를 길게 늘려줌
		longMusic += music.repeat(Math.floor(playTime / musiclength)) + music.substr(0, playTime % musiclength);
		// 재생된 노래안에 입력된 멜로디가 존재할 경우
		if (longMusic.includes(melody)) {
			// 재생시간과 노래제목을 배열에 저장
			correctArr.push([playTime, musicInfoSplit[1]]);
		}
	});
	// 일치하는 노래가 없을 경우
	if (correctArr.length === 0) {
		answer = '(None)';
	}
	// 일치하는 노래가 있을 경우
	else {
		// 노래 재생시간이 긴 순대로 정렬
		correctArr.sort((a, b) => {
			return b[0] - a[0];
		});
		// 배열의 첫번째 노래 제목이 정답
		answer = correctArr[0][1];
	}

	return answer;
}
