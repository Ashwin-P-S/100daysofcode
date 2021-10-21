package add;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class AddRecord extends JFrame implements ActionListener{

	JLabel name, id, exp, address, message;
	JTextField tName, tId, tExp, tAddress;
	JButton submitButton, clearButton;
	Font myFont = new Font("Gadugi", Font.PLAIN, 18);

	public AddRecord() {

		name = new JLabel(" Employee Name: ");
		id = new JLabel(" Employee Id: ");
		exp = new JLabel(" Years of Experience: ");
		address = new JLabel(" Home Location: ");
		message = new JLabel();

		name.setFont(myFont);
		id.setFont(myFont);
		exp.setFont(myFont);
		address.setFont(myFont);
		message.setFont(myFont);

		tName = new JTextField(25);
		tId = new JTextField(25);
		tExp = new JTextField(25);
		tAddress = new JTextField(25);

		submitButton = new JButton(" Add Record ");
		clearButton = new JButton(" Clear ");

		name.setBounds(50, 50, 250, 25);
		id.setBounds(50, 100, 250, 25);
		exp.setBounds(50, 150, 250, 25);
		address.setBounds(50, 200, 250, 25);
		message.setBounds(50, 400, 450, 25);

		tName.setBounds(300, 50, 250, 30);
		tId.setBounds(300, 100, 250, 30);
		tExp.setBounds(300, 150, 250, 30);
		tAddress.setBounds(300, 200, 250, 30);

		submitButton.setBounds(150, 300, 150, 30);
		clearButton.setBounds(350, 300, 150, 30);

		tName.setFont(myFont);
		tId.setFont(myFont);
		tExp.setFont(myFont);
		tAddress.setFont(myFont);

		submitButton.setFont(myFont);
		clearButton.setFont(myFont);

		add(name);add(id);add(exp);add(address);add(message);
		add(tName);add(tId);add(tExp);add(tAddress);
		add(submitButton);add(clearButton);

		setIconImage(Toolkit.getDefaultToolkit().getImage("./favicon.png"));
		setSize(1000, 750);
		setLayout(null);
		setVisible(true);
		setTitle(" Add Employee Data ");

		submitButton.addActionListener(this);
		clearButton.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e ) { 
				tName.setText(null);
				tId.setText(null);
				tExp.setText(null);
				tAddress.setText(null);
				message.setText(null);
			}
		});

	}

	public void actionPerformed(ActionEvent e) {

		try {
			
			String EmpName = tName.getText();
			String EmpId = tId.getText();
			String EmpExp = tExp.getText();
			String EmpAddress = tAddress.getText();

			if( EmpName.isEmpty() || EmpId.isEmpty() || EmpExp.isEmpty() || EmpAddress.isEmpty() )
			{
				message.setText(" Please Enter All Details! ");
			}
			else {

				File detailsFile = new File("./details.txt");

				if( !detailsFile.exists() ) { detailsFile.createNewFile(); }
				
				PrintWriter addRec = new PrintWriter(new FileWriter(detailsFile, true));

				addRec.println(EmpName + "-" + EmpId + "-" + EmpExp + "-" + EmpAddress);

				addRec.close();

				tName.setText(null);
				tId.setText(null);
				tExp.setText(null);
				tAddress.setText(null);
				message.setText(" SuccessFully Added " + EmpName);
			}

		} catch ( Exception exc ) { message.setText("Error: " + exc.getMessage()); }

	}

}