const addBookForm = document.getElementById("addBookForm");

// Check local storage for existing data
const books = JSON.parse(localStorage.getItem("books")) || [];

// Function to render books on the shelves
function renderBooks() {
  const unfinishedShelf = document.getElementById("unfinishedShelf");
  const finishedShelf = document.getElementById("finishedShelf");

  unfinishedShelf.innerHTML = "<h2>Belum Selesai Dibaca</h2>";
  finishedShelf.innerHTML = "<h2>Selesai Dibaca</h2>";

  books.forEach((book) => {
    const bookElement = createBookElement(book);
    if (book.isComplete) {
      const moveButton = createMoveButton(book.id);
      bookElement.appendChild(moveButton);
      finishedShelf.appendChild(bookElement);
    } else {
      unfinishedShelf.appendChild(bookElement);
    }
  });
}

// Function to create a book element
function createBookElement(book) {
  const bookElement = document.createElement("div");
  bookElement.classList.add("book");
  bookElement.innerHTML = `${book.title} by ${book.author} (${book.year})`;

  const actionButton = document.createElement("button");
  actionButton.textContent = book.isComplete ? "Hapus" : "Pindahkan";
  actionButton.addEventListener("click", () => {
    if (book.isComplete) {
      deleteBook(book.id);
    } else {
      moveBook(book.id);
    }
  });

  bookElement.appendChild(actionButton);
  return bookElement;
}

// Function to create a move button for finished books
function createMoveButton(bookId) {
  const moveButton = document.createElement("button");
  moveButton.textContent = "Pindahkan ke Belum Selesai Dibaca";
  moveButton.addEventListener("click", () => {
    moveBookToUnfinished(bookId);
  });

  return moveButton;
}

// Function to move a finished book to the unfinished shelf
function moveBookToUnfinished(bookId) {
  const index = books.findIndex((book) => book.id === bookId);
  if (index !== -1) {
    books[index].isComplete = false;
    localStorage.setItem("books", JSON.stringify(books));
    renderBooks();
  }
}

// Function to add a new book
function addBook(title, author, year, isComplete) {
  const newBook = {
    id: +new Date(),
    title: String(title), // Ensure title is a string
    author: String(author), // Ensure author is a string
    year: Number(year), // Ensure year is a number
    isComplete: isComplete === "true",
  };

  books.push(newBook);
  localStorage.setItem("books", JSON.stringify(books));
  renderBooks();
}

// Function to move a book between shelves
function moveBook(bookId) {
  const index = books.findIndex((book) => book.id === bookId);
  if (index !== -1) {
    books[index].isComplete = true;
    localStorage.setItem("books", JSON.stringify(books));
    renderBooks();
  }
}

// Function to delete a book
function deleteBook(bookId) {
  const index = books.findIndex((book) => book.id === bookId);
  if (index !== -1) {
    books.splice(index, 1);
    localStorage.setItem("books", JSON.stringify(books));
    renderBooks();
  }
}

// Event listener for form submission
addBookForm.addEventListener("submit", function (event) {
  event.preventDefault();
  const title = document.getElementById("title").value;
  const author = document.getElementById("author").value;
  const year = document.getElementById("year").value;
  const isComplete = document.getElementById("isComplete").value;

  addBook(title, author, year, isComplete);
  addBookForm.reset();
});

function createUnfinishedBookElement(book) {
  const bookElement = createBookElement(book);

  const deleteButton = document.createElement("button");
  deleteButton.textContent = "Hapus";
  deleteButton.addEventListener("click", () => {
    deleteBook(book.id);
  });

  bookElement.appendChild(deleteButton);
  return bookElement;
}

// Function to render books on the shelves with delete button
function renderBooks() {
  const unfinishedShelf = document.getElementById("unfinishedShelf");
  const finishedShelf = document.getElementById("finishedShelf");

  unfinishedShelf.innerHTML = "<h2>Belum Selesai Dibaca</h2>";
  finishedShelf.innerHTML = "<h2>Selesai Dibaca</h2>";

  books.forEach((book) => {
    if (book.isComplete) {
      const moveButton = createMoveButton(book.id);
      const finishedBookElement = createBookElement(book);
      finishedBookElement.appendChild(moveButton);
      finishedShelf.appendChild(finishedBookElement);
    } else {
      const unfinishedBookElement = createUnfinishedBookElement(book);
      unfinishedShelf.appendChild(unfinishedBookElement);
    }
  });
}

// Initial rendering
renderBooks();
