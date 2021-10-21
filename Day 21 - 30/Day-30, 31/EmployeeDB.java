
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import add.AddRecord;
import display.DisplayRecord;
import search.SearchRecord;
import delete.DeleteRecord;

public class EmployeeDB extends JFrame implements ActionListener {

	EmployeeDB () {

		JLabel welcome = new JLabel(" Welcome to Employee DataBase ");
		JButton addRecord = new JButton(" Add Record ");
		JButton viewRecord = new JButton( " View Records " );
		JButton searchRecord = new JButton( " Search Record " );
		JButton deleteRecord = new JButton( " Delete Record " );
		Image icon = Toolkit.getDefaultToolkit().getImage("./favicon.png");

		Font hFont = new Font("Gadugi", Font.BOLD , 25);
		Font eFont = new Font("Gadugi", Font.BOLD , 18);

		welcome.setBounds(300, 100, 400, 30);
		addRecord.setBounds(400, 200, 200, 30);
		viewRecord.setBounds(400, 250, 200, 30);
		searchRecord.setBounds(400, 300, 200, 30);
		deleteRecord.setBounds(400, 350, 200, 30);

		welcome.setFont(hFont);
		addRecord.setFont(eFont);
		viewRecord.setFont(eFont);
		searchRecord.setFont(eFont);
		deleteRecord.setFont(eFont);

		addRecord.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e ) { new AddRecord(); }
		} );

		viewRecord.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e ) { new DisplayRecord(); }
		} );

		searchRecord.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e ) { new SearchRecord(); }
		} );

		deleteRecord.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e ) { new DeleteRecord(); }
		} );

		add( welcome );
		add( viewRecord );
		add( addRecord );
		add( searchRecord );
		add( deleteRecord );

		setIconImage(icon);
		setSize(1000, 750);
		setLayout(null);
		setVisible(true);
		setTitle( " Employee DataBase " );
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

	public void actionPerformed( ActionEvent e ) { }
	public static void main ( String args [] ) { new EmployeeDB(); }

}