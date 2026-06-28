interface Test {
    void square(int n);
}

class Arithmetic implements Test {
    public void square(int n) {
        System.out.println("Square of " + n + " is " + (n * n));
    }
}

public class ToTestInt {
    public static void main(String[] args) {
        Arithmetic obj = new Arithmetic();
        obj.square(5);
        obj.square(9);
    }
}