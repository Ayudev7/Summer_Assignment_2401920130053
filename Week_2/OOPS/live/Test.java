package live;
 
import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;
 
public class Test {
    public static void main(String[] args) {
 
        System.out.println("===== Part A: Veena instance calling play() =====");
        Veena veena = new Veena();
        veena.play();
 
        System.out.println("\n===== Part B: Saxophone instance calling play() =====");
        Saxophone saxophone = new Saxophone();
        saxophone.play();
 
        System.out.println("\n===== Part C: Playable reference calling play() =====");
 
        // Veena object stored in Playable type variable
        Playable p1 = new Veena();
        p1.play();
 
        // Saxophone object stored in Playable type variable
        Playable p2 = new Saxophone();
        p2.play();
    }
}
 