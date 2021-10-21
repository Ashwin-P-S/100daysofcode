package display;

import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DisplayRecord extends JFrame {

	JLabel name, id, exp, location;
	JLabel eName, eId, eExp, eLocation, message;

	public DisplayRecord() {

		Font hFont = new Font("Gadugi", Font.BOLD, 20);
		Font eFont = new Font("Gadugi", Font.PLAIN, 18);

		name = new JLabel("Name");
		id = new JLabel("Id No");
		exp = new JLabel("Experience");
		location = new JLabel("Location");
		message = new JLabel(" No Records Found in DataBase ! ");

		name.setFont(hFont);
		id.setFont(hFont);
		exp.setFont(hFont);
		location.setFont(hFont);
		message.setFont(hFont);

		name.setBounds(150, 35, 150, 30);
		id.setBounds(350, 35, 150, 30);
		exp.setBounds(450, 35, 150, 30);
		location.setBounds(600, 35, 150, 30);
		message.setBounds(200, 60, 500, 30);

		try {

			File detailsFile = new File("./details.txt");

			if( !detailsFile.exists() || detailsFile.length() == 0 ) { add(message); }
			else 
			{
				add(name);add(id);
				add(exp);add(location);

				Scanner rec = new Scanner(detailsFile);
				int space = 65;

				while(rec.hasNextLine()) {

					String[] details = rec.nextLine().split("-");

					eName = new JLabel(details[0]);
					eId = new JLabel(details[1]);
					eExp = new JLabel(details[2] + " Years");
					eLocation = new JLabel(details[3]);

					eName.setBounds(150, space, 150, 30);
					eId.setBounds(350, space, 150, 30);
					eExp.setBounds(450, space, 150, 30);
					eLocation.setBounds(600, space, 150, 30);

					eName.setFont(eFont);
					eId.setFont(eFont);
					eExp.setFont(eFont);
					eLocation.setFont(eFont);

					add(eName);add(eId);
					add(eExp);add(eLocation);
					space += 25;
				}
				rec.close();
			}
		} catch ( Exception e ) { }

		setIconImage(Toolkit.getDefaultToolkit().getImage("./favicon.png"));
		setSize( 1000, 750 );
		setLayout(null);
		setVisible(true);
		setTitle( " Records in DataBase " );

	}

}