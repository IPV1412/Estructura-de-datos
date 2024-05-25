import javax.swing.*;
import java.awt.*;

public class Poligono extends JPanel {

    private int numLados;
    private int radio;

    public Poligono(int numLados, int radio) {
    this.numLados = numLados;
    this.radio = radio;
}

@Override
protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2d = (Graphics2D) g;

    int centroX = getWidth() / 2;
    int centroY = getHeight() / 2;

    int[] xPoints = new int[numLados];
    int[] yPoints = new int[numLados];

    for (int i = 0; i < numLados; i++) {
        double angulo = 2 * Math.PI * i / numLados;
        xPoints[i] = (int) (centroX + radio * Math.cos(angulo));
        yPoints[i] = (int) (centroY + radio * Math.sin(angulo));
    }

    g2d.drawPolygon(xPoints, yPoints, numLados);
}

public static void main(String[] args) {
    int numLados = 6; // Número de lados del polígono
    int radio = 100; // Radio del polígono

    JFrame frame = new JFrame("Dibujando un polígono");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new Poligono(numLados, radio));
    frame.setSize(300, 300);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);
}
}
