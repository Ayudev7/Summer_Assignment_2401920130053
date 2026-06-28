class Point {
    private int x, y;

    public Point() {
        x = 0;
        y = 0;
    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void display() {
        System.out.println("Point(" + x + ", " + y + ")");
    }
}

public class TestPoint {
    public static void main(String[] args) {
        Point p1 = new Point();
        p1.display();

        Point p2 = new Point(3, 4);
        p2.display();

        p1.setX(10);
        p1.setY(20);
        p1.display();

        p2.setXY(7, 8);
        p2.display();
    }
}