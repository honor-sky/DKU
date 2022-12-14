import java.util.Random;


public class Ex1 {
	
	/*배열에서 자기 자신을 제외하고 같은 값을 갖는 원소를 찾으면 종료하는 알고리즘*/
	 public static int any_equal(int n, int A[][]) {
				
		int i, j, k, m;
		for(i = 1;i<=n;i++) {
			for(j =1;j<=n;j++) {
				for(k =1;k<=n;k++) {
					for(m =1;m<=n;m++) {
						if(A[i][j]==A[k][m] &&! (i==k && j==m)) { //True면 서로 다른 위치에 있는 원소의 값이 같음
							return 1;
						}
							
					}
				}
			}
		}
		return 0; //배열 A에는 같은 값을 갖는 원소가 단 1개도 없다	
	 }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		

		int result,index;
		int array[][] = new int[100][100];
		
		
		Random rd = new Random(123);//재현성 보장 위해 seed 값 설정
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				array[i][j] = (int)(rd.nextInt(1000000000)); 
			}	
		}
		
		/*
		for(int i=0;i<100;i++) {//배열의 원소 출력 
			for(int j=0;j<100;j++) {
				System.out.println(array[i][j]);
			}
		}
		*/
		
		long start_time = System.currentTimeMillis(); //시작 시간
		result = any_equal(90,array);
		long end_time = System.currentTimeMillis(); //종료 시간
		
		System.out.println(result);
		System.out.println("시작 시간"+start_time);
		System.out.println("종료 시간"+end_time);
		System.out.println("경과시간: "+(end_time-start_time)); //40ms 출력 //(c)적용하면 35ms 출력

	}

}

/*(a) 최선 시간복잡도를 구하시오
 *  i, j, k가 모두 1 이고 m이 2일 때 즉, A[1][1]==A[1][2]이면 
 *  바로 1을 반환하면서 메소드가 끝나게 되므로 최선의 시간복잡도는 m 반복문의 2번째 실행을 하고 종료되는
 *  B(n)=2 이다. */

/*(b) 최악 시간복잡도를 구하시오
 * 최악의 시간복잡도는 배열의 모든 경우를 다 검사하는 경우이다.
 * 따라서 W(n)=n^4 이다. */

/*(c) 알고리즘의 효율을 향상시키시오
 * A[1][1] == A[1][1] 처럼 자기 자신을 검사하는 경우와 A[1][1] == A[1][2], A[1][2] == A[1][1]처럼 중복 검사하는 경우를 제거하여 효율 향상
 * 실행시간이 40ms 에서 35ms로 5ms정도 줄었다
 * public static int any_equal(int n, int A[][]) {
				
		int i, j, k, m;
		//중복 검사, 자기 자신끼리 검사 제외 //and 연산 제거
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) { //A[i][j]
				for(k=i;k<=n;k++) {
					if(k==i) {
						for(m=j+1;m<=n;m++) { //j다음부터
							if(A[i][j]==A[k][m]) {
								return 1;
							}		
						}
					}else {
					    for(m=1;m<=n;m++) { //처음부터
							if(A[i][j]==A[k][m]) {
								return 1;
						    }
					    }
				    }
			   }
		   }
	    }
		return 0; 
		
	 }
*/
/*(d) 0을 내주는 경우 배열 A의 성질은?
 * 배열 A에는 같은 값을 갖는 원소가 단 1개도 없다*/

/*(e) 1을 내주는 경우 배열 A의 성질은?
 * 배열 A에는 같은 값을 갖는 원소들이 1개 이상 있다*/

