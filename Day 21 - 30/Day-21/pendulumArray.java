import java.util.Scanner;

class pendulumArray {

    public static void main(String[] arg) {

        Scanner in = new Scanner(System.in);
        // Clears Screen
        System.out.println("\033[H\033[2J");
        System.out.flush();

        System.out.print("\n\n\t\t Simple Pendulum Motion !");
        System.out.print("\n\n Enter the Size of the Array: ");
        int size = in.nextInt();

        int array[] = new int[size];    // Dynamic Array Size
        System.out.print("\n\n Enter Element One-by-one:\n\n");
        for(int i = 0; i < size; i++) array[i] = in.nextInt();

        pendulumArray(array, size);
    }

    static void pendulumArray(int array[], int size) {

        int sp[] = new int[size], temp = 0, mid = (int) (size - 1) / 2;
        for(int i = 0; i < size; i++) sp[i] = 0;

        // Sorting the Array
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(array[i] > array[j])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

        // Let's Sort as Simple Pendulum
        sp[mid] = array[0];
        int i = 1, j = 1;
        for(i = 1; i <= mid; i++){
            sp[mid + i] = array[j++];
            sp[mid - i] = array[j++];
        }

        // Corrections if Size of the Array is Even
        if(size % 2 == 0) sp[mid + i] = array[j];

        System.out.print("\n\n Simple Pendulum Motion: ");
        for(i = 0; i < size; i++) System.out.print(sp[i] + " ");
    }

}