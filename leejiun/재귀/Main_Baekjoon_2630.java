import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_Baekjoon_2630
{
    static  int numOfWhite = 0, numOfBlack = 0;
    static char[][] map;
	public static void main(String[] args) throws Exception{
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   int size = Integer.parseInt(br.readLine());
	   map= new char[size][size];
	   
	   
	   for(int i = 0; i < size; i++){
	       String line = br.readLine();
	       for(int j = 0,index=0; j < size; j++,index+=2){
	           map[i][j] = line.charAt(index);
	       }
	   }//input
	   
	   makeColoredPaper(0,0,size);
	 
	   System.out.println(numOfWhite);
	   System.out.println(numOfBlack);
	}
	
	static public void makeColoredPaper(int r, int c, int size){
	    if(size == 1 || isSameRectangle(r,c,size)){//정사각형이 모두 같은 색깔이면
	        if(map[r][c] == '0') {//흰색이면
	        	 numOfWhite += 1;//흰색깔 증가
	        }else {
	        	numOfBlack += 1;//검정색깔 증가
	        }
	    }else{
	        int n = size/2;
	        makeColoredPaper(r,c,n);
    	    makeColoredPaper(r,c+n,n);
    	    makeColoredPaper(r+n,c,n);
    	    makeColoredPaper(r+n,c+n,n);
	    }
	}// 색종이 만들기
	
	static public boolean isSameRectangle(int r, int c, int size){
	    char start = map[r][c];
	    for(int i = r; i < r+size; i++){
	        for(int j = c; j <c+ size; j++){
	            if(map[i][j] != start)
	                return false; // 정사각형이 아님
	        }
	    }
	    return true; //모두 같은 색깔의 사각형
	}
}
