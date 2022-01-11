import java.util.*;

class Main {

    static boolean isPalindrome(String word) {

        int i = 0, j = word.length()-1;
        while(i<j) {
            if(word.charAt(i) != word.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }

    public static void main(String [] arg) {

        Scanner in = new Scanner(System.in);
        String word;

        System.out.print("\n Palindrome Program for Strings\n");
        System.out.print("\n Enter String: ");
        word = in.nextLine();

        if(isPalindrome(word))
            System.out.println("\n Given String is Palindrome");
        else
            System.out.println("\n Given String is not Palindrome");
    }
}