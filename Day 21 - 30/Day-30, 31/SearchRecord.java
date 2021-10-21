package search;

import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SearchRecord extends JFrame implements ActionListener {

	JLabel searchTitle, searchId, message;
	JTextField tSearchId;
	JButton searchButton;

	JLabel lName = new JLabel();
	JLabel lId = new JLabel();
	JLabel lExp = new JLabel();
	JLabel lLocation = new JLabel();

	Font hFont = new Font("Gadugi", Font.BOLD, 20);
	Font eFont = new Font("Gadugi", Font.PLAIN, 18);

	public SearchRecord() {

		searchTitle = new JLabel(" Search Record in Database ");
		message = new JLabel(" Details to Search ");
		searchId = new JLabel(" Id of the Employee: ");

		tSearchId = new JTextField();
		searchButton = new JButton(" Search ");

		searchTitle.setFont(hFont);
		message.setFont(eFont);
		searchId.setFont(hFont);

		tSearchId.setFont(eFont);
		searchButton.setFont(eFont);

		searchTitle.setBounds(350, 35, 400, 30);
		message.setBounds(400, 75, 250, 30);
		searchId.setBounds(200, 150, 300, 30);

		tSearchId.setBounds(450, 150, 250, 30);
		searchButton.setBounds(200, 200, 100, 30);

		searchButton.addActionListener(this);

		add(searchTitle); add(message);
		add(searchId); add(tSearchId); add(searchButton);

		setIconImage(Toolkit.getDefaultToolkit().getImage("./favicon.png"));
		setSize(1000, 750);
		setLayout(null);
		setTitle(" Search Employee Data");
		setVisible(true);

	}

	public void actionPerformed( ActionEvent e ) { 

		String sId = tSearchId.getText();

		if( sId.isEmpty() ) { 
			message.setText("Please Enter Id No. !");
			lName.setText(null);lId.setText(null);
			lExp.setText(null);lLocation.setText(null);
			return;
		}

		try {

			File detailsFile = new File("./details.txt");

			if( !detailsFile.exists() || detailsFile.length() == 0 ) { 

				message.setText("No Records in DataBase "); 

			}  else {

				Scanner scanFile = new Scanner(detailsFile);

				int flag = 0;

				while(scanFile.hasNextLine()) {
					String[] details = scanFile.nextLine().split("-");
					if( sId.equals(details[1]) ) { 
						lName.setText("Name:           " + details[0]);
						lId.setText("Id:                 " + details[1]);
						lExp.setText("Experience:   " + details[2] + " Years");
						lLocation.setText("Location:       " + details[3]);
						message.setText(" Record Found !");
						flag = 1;
					}
				}

				if( flag == 0 ) { 
					message.setText("Id " + sId + " is not Found !");
					lName.setText(null);lId.setText(null);
					lExp.setText(null);lLocation.setText(null);
				}

				scanFile.close();
			}

		} catch ( Exception exc ) { message.setText("Error: " + exc.getMessage()); }

		lName.setBounds(350, 275, 500, 30);
		lId.setBounds(350, 300, 500, 30);
		lExp.setBounds(350, 325, 500, 30);
		lLocation.setBounds(350, 350, 500, 30);

		add(lName);add(lId);
		add(lExp);add(lLocation);

		lName.setFont(eFont); lId.setFont(eFont);
		lExp.setFont(eFont); lLocation.setFont(eFont);

	}

}