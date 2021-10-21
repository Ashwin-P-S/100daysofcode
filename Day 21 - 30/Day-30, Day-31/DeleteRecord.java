package delete;

import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DeleteRecord  extends JFrame implements ActionListener{

	JLabel title, message, lId;
	JTextField tId;
	JButton deleteButton;

	public DeleteRecord() {

		title = new JLabel(" Delete a Particular Record ");
		message = new JLabel(" Details to Delete ");

		lId = new JLabel(" Id of the Employee: ");
		tId = new JTextField();
		deleteButton = new JButton(" Search & Delete ");

		deleteButton.addActionListener(this);

		Font hFont = new Font("Gadugi", Font.BOLD, 20);
		Font eFont = new Font("Gadugi", Font.PLAIN, 18);

		title.setBounds(350, 35, 400, 30);
		message.setBounds(400, 75, 250, 30);
		lId.setBounds(200, 150, 300, 30);
		tId.setBounds(450, 150, 250, 30);
		deleteButton.setBounds(200, 200, 200, 30);

		title.setFont(hFont);
		message.setFont(eFont);
		lId.setFont(eFont);
		tId.setFont(eFont);
		deleteButton.setFont(eFont);

		add(title); add(message);
		add(lId); add(tId); add(deleteButton);

		setIconImage(Toolkit.getDefaultToolkit().getImage("./favicon.png"));
		setSize(1000, 750);
		setLayout(null);
		setVisible(true);
		setTitle(" Delete Record ");

	}

	public void actionPerformed( ActionEvent e ) {


		if( tId.getText().isEmpty() ) {
			message.setText(" Please Enter Id No. ! ");
			message.setBounds(400, 75, 250, 30);
			return;
		}

		try {

			File detailsFile = new File("./details.txt");

			String sId = tId.getText();

			if( !detailsFile.exists() || detailsFile.length() == 0 ) {
				message.setText("No Records in the DataBase ");
				message.setBounds(370, 75, 500, 30);
				return;
			}

			File tempFile = new File("./temp.txt");
			tempFile.createNewFile();
			
			PrintWriter pr = new PrintWriter(new FileWriter(tempFile));
			Scanner scanFile = new Scanner(detailsFile);
			int flag = 0;

			while( scanFile.hasNextLine() ) {

				String[] details = scanFile.nextLine().split("-");
				if( !sId.equals(details[1]) ) {
					pr.println(details[0] + "-" + details[1] + "-" +details[2] + "-" + details[3]);
					pr.flush();
				}
				if( sId.equals(details[1]) ) { 
					flag = 1;
					message.setText(" Id " + details[1] + " is Deleted Successfully! "); 
					message.setBounds(350, 75, 500, 30);
				}
			}

			if( flag == 0 ) { 
				message.setText(" Id " + sId + " is Not Found! ");  
				message.setBounds(400, 75, 250, 30);
			}

			pr.close();
			scanFile.close();

			detailsFile.delete();
			tempFile.renameTo(detailsFile);

		} catch ( Exception exc ) { message.setText(" Error: " + exc.getMessage()); }
	}
}