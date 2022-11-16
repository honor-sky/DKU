import java.util.Random;


public class Ex1 {
	
	/*�迭���� �ڱ� �ڽ��� �����ϰ� ���� ���� ���� ���Ҹ� ã���� �����ϴ� �˰���*/
	 public static int any_equal(int n, int A[][]) {
				
		int i, j, k, m;
		for(i = 1;i<=n;i++) {
			for(j =1;j<=n;j++) {
				for(k =1;k<=n;k++) {
					for(m =1;m<=n;m++) {
						if(A[i][j]==A[k][m] &&! (i==k && j==m)) { //True�� ���� �ٸ� ��ġ�� �ִ� ������ ���� ����
							return 1;
						}
							
					}
				}
			}
		}
		return 0; //�迭 A���� ���� ���� ���� ���Ұ� �� 1���� ����	
	 }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		

		int result,index;
		int array[][] = new int[100][100];
		
		
		Random rd = new Random(123);//������ ���� ���� seed �� ����
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				array[i][j] = (int)(rd.nextInt(1000000000)); 
			}	
		}
		
		/*
		for(int i=0;i<100;i++) {//�迭�� ���� ��� 
			for(int j=0;j<100;j++) {
				System.out.println(array[i][j]);
			}
		}
		*/
		
		long start_time = System.currentTimeMillis(); //���� �ð�
		result = any_equal(90,array);
		long end_time = System.currentTimeMillis(); //���� �ð�
		
		System.out.println(result);
		System.out.println("���� �ð�"+start_time);
		System.out.println("���� �ð�"+end_time);
		System.out.println("����ð�: "+(end_time-start_time)); //40ms ��� //(c)�����ϸ� 35ms ���

	}

}

/*(a) �ּ� �ð����⵵�� ���Ͻÿ�
 *  i, j, k�� ��� 1 �̰� m�� 2�� �� ��, A[1][1]==A[1][2]�̸� 
 *  �ٷ� 1�� ��ȯ�ϸ鼭 �޼ҵ尡 ������ �ǹǷ� �ּ��� �ð����⵵�� m �ݺ����� 2��° ������ �ϰ� ����Ǵ�
 *  B(n)=2 �̴�. */

/*(b) �־� �ð����⵵�� ���Ͻÿ�
 * �־��� �ð����⵵�� �迭�� ��� ��츦 �� �˻��ϴ� ����̴�.
 * ���� W(n)=n^4 �̴�. */

/*(c) �˰����� ȿ���� ����Ű�ÿ�
 * A[1][1] == A[1][1] ó�� �ڱ� �ڽ��� �˻��ϴ� ���� A[1][1] == A[1][2], A[1][2] == A[1][1]ó�� �ߺ� �˻��ϴ� ��츦 �����Ͽ� ȿ�� ���
 * ����ð��� 40ms ���� 35ms�� 5ms���� �پ���
 * public static int any_equal(int n, int A[][]) {
				
		int i, j, k, m;
		//�ߺ� �˻�, �ڱ� �ڽų��� �˻� ���� //and ���� ����
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) { //A[i][j]
				for(k=i;k<=n;k++) {
					if(k==i) {
						for(m=j+1;m<=n;m++) { //j��������
							if(A[i][j]==A[k][m]) {
								return 1;
							}		
						}
					}else {
					    for(m=1;m<=n;m++) { //ó������
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
/*(d) 0�� ���ִ� ��� �迭 A�� ������?
 * �迭 A���� ���� ���� ���� ���Ұ� �� 1���� ����*/

/*(e) 1�� ���ִ� ��� �迭 A�� ������?
 * �迭 A���� ���� ���� ���� ���ҵ��� 1�� �̻� �ִ�*/

