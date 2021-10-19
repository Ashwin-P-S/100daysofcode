import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class FindIP extends Frame implements ActionListener {

    Label showIp, noteUser;
    Button findIp;
    TextField searchWeb;

    FindIP() {

        noteUser = new Label(" Enter URL to Find IP ");
        showIp = new Label();
        findIp = new Button(" Find IP ");
        searchWeb = new TextField();

        noteUser.setBounds(50, 50, 150, 25);
        searchWeb.setBounds(50, 100, 150, 25);
        showIp.setBounds(50, 150, 350, 25);
        findIp.setBounds(50, 200, 160, 30);

        findIp.addActionListener( this );
        addWindowListener( new WindowAdapter() {
            public void windowClosing ( WindowEvent e ) { dispose(); }
        });

        add(noteUser);
        add(showIp);
        add(findIp);
        add(searchWeb);

        setLayout(null);
        setSize(400, 400);
        setVisible(true);
        setTitle(" Find IP Address ");

    }

    public void actionPerformed( ActionEvent e ) {

        try {

            String hostName = searchWeb.getText();
            String ipAddress = java.net.InetAddress.getByName(hostName).getHostAddress();
            showIp.setText(" IP Address of " + hostName + ": " + ipAddress);
            noteUser.setText(" IP Address Found ");

        } catch ( Exception exc ) { 
            
            showIp.setText(exc.getMessage()); 
            noteUser.setText(" IP Address Not Found ");

        }

    }

    public static void main ( String args [] ) { 

        try { UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel"); }
        catch ( Exception e ) { }
        new FindIP(); 

    }

}