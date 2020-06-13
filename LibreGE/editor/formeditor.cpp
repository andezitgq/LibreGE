#include "formeditor.h"
#include "ui_formeditor.h"

FormEditor::FormEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormEditor)
{
    ui->setupUi(this);
    setupEditor();
}

FormEditor::~FormEditor()
{
    delete ui;
}

void FormEditor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    codeEditor = ui->codeEdit1;
    codeEditor->setFont(font);

    highlighter = new Highlighter(codeEditor->document());

    QFile file("/home/freelogger/sas.txt");
    if (file.open(QFile::ReadOnly | QFile::Text))
        codeEditor->setPlainText(file.readAll());
}
