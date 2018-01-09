//1、在EDIT中的显示


	CString strText_1(_T(""));
	strText_1.Format(_T("%d"), temp_1);
	SetDlgItemText(IDC_EDIT16,strText_1);



//2、从txt文件中读取数据
	vector<double>m_data;
    TCHAR path[255];  
    //桌面目录  
    SHGetSpecialFolderPath(0,path,CSIDL_DESKTOPDIRECTORY,0);   
    CString filepath;  
    filepath  = "RSSI.txt";              
  
    CStdioFile m_file;
	m_file.Open(filepath,CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite | CFile::shareDenyNone);  
	CString contents;  
	int temp = 0; 


    while(m_file.ReadString(contents)) 
    {  
		temp = atoi(contents);
		xprintf("%d\n",temp);
        m_data.push_back(temp);                   
    }  
	m_file.Close();
  
  
  
  
