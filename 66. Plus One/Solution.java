package plusOne;

public class Solution {
    public int[] plusOne(int[] digits) {
        //�Ӻ���ǰ����һ��С��9�ģ��Ϳ���break����������ĵ���9�ľ͸���Ϊ0
        for(int i = digits.length-1; i>=0; i--){
            if(digits[i]<9){
                digits[i]++;
                break;
            }else{
                digits[i]=0;
            }
        }
        //�߽���������ȫΪ9ʱ�����½�һ�����飬��һλ1������λͬdigits
        if(digits[0]==0){
            int[] newdigits = new int[digits.length+1];
            newdigits[0]=1;
            for(int i=1;i<newdigits.length;i++){
                newdigits[i]=digits[i-1];
            }
             return newdigits;
        }
        //����ֱ��return digits
        return digits;
    }
}
