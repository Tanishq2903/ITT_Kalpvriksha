import { useState } from 'react';
import {Menu , BookmarkAdd ,ExpandMore,MenuIcon} from '@mui/icons-material';
import { AppBar, Toolbar,styled,Box,Typography,InputBase } from "@mui/material";
import { logoURL } from "../consants/consant";
import { useNavigate } from 'react-router-dom';
import HeaderMenu from './HeaderMenu';
import { routePath } from '../consants/route';
import { useRef } from 'react';

const StyledToolBar = styled(Toolbar)`
    background: #121212;
    min-height: 56px !important;
    padding: 0 115px !important;
    justify-content: space-between;
    & > * {
        padding: 0 16px;
    }
    & > div {
        display: flex;
        align-items: center;
        cursor: pointer;
        & > p {
            font-weight: 600;
            font-size: 14px;
        }
    }
    & > p {
        font-weight: 600;
        font-size: 14px;
    }
`;

const InputSearchField = styled(InputBase)`
    background: #FFFFFF;
    height: 30px;
    width: 55%;
    border-radius: 5px;
`

const Logo = styled('img')({
    width: 64,
})

const Header = () => {

    const [open, setOpen] = useState(false);

    const anchorRef = useRef(null);

    const navigate = useNavigate();

    const handleToggle = () => {
        setOpen(prev => !prev);
    };

    return (
        <AppBar style={{ minHeight: 56 }} position='static'>
            <StyledToolBar>
                <Logo src={logoURL} alt="logo" onClick={() => navigate(routePath.home)} />
                <Box ref={anchorRef} onClick={handleToggle}>
                    {/* <MenuIcon /> */}
                    <Typography>Menu</Typography>
                </Box>
                <HeaderMenu handleToggle={handleToggle} open={open} anchorRef={anchorRef} />
                <InputSearchField
                    variant="outlined"
                />
                <Typography>IMDb<Typography component="span" style={{ fontSize: 14 }}>Pro</Typography></Typography>
                <Box>
                    <BookmarkAdd />
                    <Typography>Watchlist</Typography>
                </Box>
                <Typography>Sign In</Typography>
                <Box>
                    <Typography>EN</Typography>
                    <ExpandMore />
                </Box>
            </StyledToolBar>
        </AppBar>
    )
}
export default Header;