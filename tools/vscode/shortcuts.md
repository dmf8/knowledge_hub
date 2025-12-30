# 基础
## 自定义快捷键
- 快捷键可以自定义
- 进入快捷键定义列表这个操作本身也有快捷键`ctrl+k ctrl+s`
- 可以通过快捷键或对应的功能名搜索快捷键
- 在快捷键面板打开keybingings.json, 可以直接编辑快捷键文件, 每个快捷键包括
    ```json
    {
        "key": "ctrl+shift+p",
        "command": "python.execInTerminal-icon",
        "when": "workbench.action.showCommands"
    }
    ```

## when clause 快捷键上下文
- 一个快捷键组合可以对应多个功能, 执行哪个功能取决于上下文条件when clause(焦点, 活跃视图等)
- 每一个功能对应一个唯一的命令id
- 可以查看每次按下快捷键的when clause判断过程
    1. [打开命令面板](#打开命令面板)
    1. 输入Developer: Toggle Keyboard Shortcuts Troubleshooting
    1. 切换到output面板
    1. 按下快捷键, 查看打印的日志

## 常见问题
- 快捷键冲突
    有些快捷键冲突, 可以通过添加/修改when条件来解决. 参见[自定义快捷键](#自定义快捷键), 查看快捷键的条件, 作出相应调整

# open
|功能描述|快捷键|菜单|命令名|条件|
|-|-|-|-|-|
|打开最近的文件和文件夹|ctrl+r|File/Open Recent|workbench.action.openRecent|
|打开所在文件夹|ctrl+alt+r||revealFileInOS|!editorFocus|

# system
|功能描述|快捷键|菜单|命令名|
|-|-|-|-|
|打开命令面板<a id="打开命令面板"></a>|ctrl+shift+p|View/Command Palette|workbench.action.showCommands|
|编辑快捷键|ctrl+k ctrl+s||workbench.action.openGlobalKeybindings|

# 编辑器
|功能描述|快捷键|菜单|命令名|
|-|-|-|-|
|向右分栏|ctrl+\ ||workbench.action.splitEditor|
|关闭分栏|ctrl+k w||workbench.action.closeEditorsInGroup|
|关闭所有分栏|ctrl+k ctrl+w||workbench.action.closeAllEditors|
|开关侧边栏|ctrl+b||workbench.action.toggleSidebarVisibility| 

# 编辑 editor
|功能描述|快捷键|菜单|命令名|条件|
|-|-|-|-|-|
|切换换行|alt+z||editor.action.toggleWordWrap|
|选中光标所在单词|ctrl+d||editor.action.addSelectionToNextFindMatch|editorFocus|
|选中光标所在行(包括换行符)|ctrl+l||expandLineSelection|textInputFocus|
|回到上个编辑位置|ctrl+alt+-||workbench.action.navigateBack|canNavigateBack|
|去到下个编辑位置|ctrl+alt+=||workbench.action.navigateForward|canNavigateForward|
|光标移到文件顶部|ctrl+home||cursorTop|textInputFocus|
|光标移到文件底部|ctrl+end||cursorBottom|textInputFocus|

# 显示
|功能描述|快捷键|菜单|命令名|
|-|-|-|-|
|缩小|ctrl+-||workbench.action.zoomOut|
|放大|ctrl+=||workbench.action.zoomIn|