#ifndef FORMEDITOR_H
#define FORMEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include "editor/highlighter.h"

namespace Ui {
class FormEditor;
}

class FormEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormEditor(QWidget *parent = nullptr);
    ~FormEditor();

private:
    Ui::FormEditor *ui;

    void setupEditor();

    QTextEdit   *codeEditor;
    Highlighter *highlighter;
};

#endif // FORMEDITOR_H
